#include "customslider.h"

CustomSlider::CustomSlider(QWidget *parent): QSlider(Qt::Horizontal, parent){}

void CustomSlider::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        updateSliderValue(event->pos());
        event->accept();
    }else{
        QSlider::mousePressEvent(event);
    }
    emit slider_clicked(this->value());
}

void CustomSlider::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        updateSliderValue(event->pos());
        event->accept();
    }else{
        QSlider::mouseMoveEvent(event);
    }
    emit slider_clicked(this->value());
}

void CustomSlider::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        updateSliderValue(event->pos());
        event->accept();
    }else{
        QSlider::mouseReleaseEvent(event);
    }
    emit slider_clicked(this->value());
}

void CustomSlider::updateSliderValue(const QPoint &pos){
    QStyleOptionSlider opt;
    initStyleOption(&opt);
    QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);
    int newVal;
    if(orientation() == Qt::Vertical){
        double halfHandleHeight = (0.5 * sr.height()) + 0.5;
        int adaptedPosY = height() - pos.y();
        if(adaptedPosY < halfHandleHeight){
            adaptedPosY = halfHandleHeight;
        }
        if(adaptedPosY > height() - halfHandleHeight){
            adaptedPosY = height() - halfHandleHeight;
        }
        double newHeight = (height() - halfHandleHeight) - halfHandleHeight;
        double normalizedPosition = (adaptedPosY - halfHandleHeight)  / newHeight ;
        newVal = minimum() + (maximum() - minimum()) * normalizedPosition;
    }else{
        double halfHandleWidth = (0.5 * sr.width()) + 0.5;
        int adaptedPosX = pos.x();
        if(adaptedPosX < halfHandleWidth){
            adaptedPosX = halfHandleWidth;
        }
        if(adaptedPosX > width() - halfHandleWidth){
            adaptedPosX = width() - halfHandleWidth;
        }
        double newWidth = (width() - halfHandleWidth) - halfHandleWidth;
        double normalizedPosition = (adaptedPosX - halfHandleWidth)  / newWidth ;

        newVal = minimum() + ((maximum() - minimum()) * normalizedPosition);
    }

    if(invertedAppearance()){
        this->setValue(maximum() - newVal);
    }else{
        this->setValue(newVal);
    }
}
