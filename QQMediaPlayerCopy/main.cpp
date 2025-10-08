
#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <string>
#include <QTranslator>


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/resources/logo.png"));

    //Translation_zh_Hans.qm
    QTranslator* trans = new QTranslator();

    //ע��·���ķ�б�ߣ������ļ����ش��󽫲��ᷭ��
    QString qm_path = a.applicationDirPath() + "/Translation_zh_Hans.qm";
    trans->load(qm_path);
    a.installTranslator(trans);

    CMainWindow w;
    w.show();
    return a.exec();
}
