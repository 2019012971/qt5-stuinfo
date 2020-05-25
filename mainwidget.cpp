#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QLabel>
#include "adminwidget.h"
#include "stuwidget.h"

MainWidget::MainWidget(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MainWidget) {
	ui->setupUi(this);
}

MainWidget::~MainWidget() {
	delete ui;
}

void MainWidget::on_loginpushButton_clicked() {
	admin_ui = new adminwidget();
	admin_ui->setWindowTitle("学生信息管理系统(管理员界面)");
	admin_ui->setWindowIcon(QIcon(":/images/logo.ico"));
	if(ui->usrlineEdit->text().trimmed() == tr("admin") && ui->pwdlineEdit->text() == tr("123456"))
		admin_ui->show();
	else {
		QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
		// 清空内容并定位光标
		ui->usrlineEdit->clear();
		ui->pwdlineEdit->clear();
		ui->usrlineEdit->setFocus();
	}
}

void MainWidget::on_stupushButton_clicked() {
	stu_ui = new stuwidget();
	stu_ui->setWindowTitle("学生信息管理系统(学生界面)");
	stu_ui->setWindowIcon(QIcon(":/images/logo.ico"));
	stu_ui->show();
}
