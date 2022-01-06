#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsDropShadowEffect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QGraphicsDropShadowEffect *shadow  = new QGraphicsDropShadowEffect();
    //设置圆角
    shadow->setBlurRadius(15);
    shadow->setColor(Qt::black);
    //设置偏移量
    shadow->setOffset(0, 0);
    ui->widget->setGraphicsEffect(shadow);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_CloseBtn_clicked()
{
    this->close();
}

//重写鼠标移动事件
void Widget::mouseMoveEvent ( QMouseEvent * event )
{
    //鼠标相对于桌面左上角的位置，全局位置
    QPoint y = event->globalPos();
    QPoint x = y-this->z;

    this->move(x);
}

//重写鼠标按下事件
void Widget::mousePressEvent ( QMouseEvent * event )
{
    //获取鼠标全局x、y坐标
    QPoint y = event->globalPos();
    QPoint x = this->geometry().topLeft();

    this->z = y - x;
}

void Widget::mouseReleaseEvent ( QMouseEvent * event )
{

}
