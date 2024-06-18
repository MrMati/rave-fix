#include "customslider.h"
#include <QMouseEvent>
#include <QDebug>
#include <QStyle>
CustomSlider::CustomSlider(QWidget *parent)
    : QSlider(parent)
{
}

void CustomSlider::mousePressEvent(QMouseEvent *event)
{
    // Calculate the value based on the click position
    int value = minimum() + ((maximum() - minimum()) * (event->x() - style()->pixelMetric(QStyle::PM_SliderLength) / 2)) / (width() - style()->pixelMetric(QStyle::PM_SliderLength));

    // Ensure the value is within the slider range
    if (value < minimum())
        value = minimum();
    else if (value > maximum())
        value = maximum();

    qDebug() << "clicked on slider: " << value;

    // Set the new value and emit the signal
    setValue(value);
    emit slider_clicked(value);

    // Propagate the event to the base class for default handling
    QSlider::mousePressEvent(event);
}
