#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>

namespace Ui {
class Config;
}

class Config : public QDialog
{
    Q_OBJECT

public:
    explicit Config(QWidget *parent = 0);
    ~Config();
    struct Params{
        int iniX;
        int iniY;
        int finX;
        int finY;
    };
    Params myParams;

private:
    Ui::Config *ui;

signals:

public slots:
    void accept();
};

#endif // CONFIG_H
