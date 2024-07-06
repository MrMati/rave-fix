#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include <QObject>
#include <QWidget>
#include <QSlider>
#include <QStyleOptionSlider>
#include <QMouseEvent>
#include <QDebug>
#include <QStyle>

class CustomSlider: public QSlider{
    Q_OBJECT
    public:
        explicit CustomSlider(QWidget *parent = nullptr);

    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;

    signals:
        void slider_clicked(int position);

    private:
        void updateSliderValue(const QPoint &pos);
};

#endif // CUSTOMSLIDER_H
