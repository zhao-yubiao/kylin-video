﻿/*
 * Copyright (C) 2013 ~ 2019 National University of Defense Technology(NUDT) & Tianjin Kylin Ltd.
 *
 * Authors:
 *  Kobe Lee    lixiang@kylinos.cn/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "soundvolume.h"
#include "slider.h"

#include <QDebug>
#include <QPainter>
#include <QWheelEvent>
#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QSlider>
#include <QTimer>

SoundVolume::SoundVolume(QWidget *parent) : QWidget(parent)
{
    this->setObjectName("SoundVolume");

    setWindowFlags(Qt::ToolTip | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(106, 40);//setFixedSize(40, 106);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 0, 5, 0);//(0, 5, 0, 11);//
    layout->setSpacing(0);


    m_volSlider  = 0;
    tborderColor = QColor(0, 0, 0,  255 * 2 / 10);
    tradius      = 4;
    mouseIn     = false;

    m_volSlider = new Slider(Qt::Horizontal);/*QSlider(Qt::Horizontal)*/
    m_volSlider->setMinimum(0);
    m_volSlider->setMaximum(100);
    //m_volSlider->setSingleStep(10);//VolumeStep
    m_volSlider->setPageStep(1);    
    m_volSlider->setFocusPolicy(Qt::NoFocus);
    m_volSlider->setObjectName("VolumeProgress");

    layout->addStretch();
    layout->addWidget(m_volSlider, 0, Qt::AlignCenter);
    layout->addStretch();
    setFixedSize(106, 24);

    connect(m_volSlider, SIGNAL(valueChanged(int)), this, SIGNAL(volumeChanged(int)));
    m_volSlider->setValue(80);
}

SoundVolume::~SoundVolume()
{

}

void SoundVolume::setValue(int vol) {
    bool was_blocked = m_volSlider->blockSignals(true);
    m_volSlider->setValue(vol);
    m_volSlider->blockSignals(was_blocked);
}

int SoundVolume::volume() const {
    return m_volSlider->value();
}

QBrush SoundVolume::background() const {
    return tbackground;
}

int SoundVolume::radius() const {
    return this->tradius;
}

QColor SoundVolume::borderColor() const {
    return this->tborderColor;
}

void SoundVolume::setBackground(QBrush m_background) {
    this->tbackground = m_background;
}

void SoundVolume::setRadius(int m_adius) {
    this->tradius = m_adius;
}

void SoundVolume::setBorderColor(QColor m_borderColor) {
    this->tborderColor = m_borderColor;
}

void SoundVolume::deleyHide() {
    this->mouseIn = false;
//    QTimer::singleShot(1000, this, SLOT(slot_deley()));
}

void SoundVolume::slot_deley() {
    if (!this->mouseIn) {
        hide();
    }
}

void SoundVolume::onVolumeChanged(int vol) {
    this->m_volSlider->blockSignals(true);
    this->m_volSlider->setValue(vol);
    this->m_volSlider->blockSignals(false);
}

void SoundVolume::showEvent(QShowEvent *event) {
    this->mouseIn = true;
    QWidget::showEvent(event);
}

void SoundVolume::enterEvent(QEvent *event) {
    this->mouseIn = true;
    QWidget::enterEvent(event);
}

void SoundVolume::leaveEvent(QEvent *event) {
    this->mouseIn = false;
    deleyHide();
    QWidget::leaveEvent(event);
}

void SoundVolume::wheelEvent(QWheelEvent *event) {
    QWidget::wheelEvent(event);
}
