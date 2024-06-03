#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include <QObject>
#include <QWidget>
#include <QSlider>

class CustomSlider: public QSlider{
    Q_OBJECT
    public:
        CustomSlider(QWidget *parent = nullptr);

    protected:
        void mousePressEvent(QMouseEvent *event) override;

    signals:
        void sliderClicked(int position);
};

#endif // CUSTOMSLIDER_H
