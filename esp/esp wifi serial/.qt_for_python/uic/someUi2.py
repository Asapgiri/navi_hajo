# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'c:\Users\Mika\Documents\pyQt5 Projects\buttonsAndStuff\someUi2.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(800, 480)
        self.label = QtWidgets.QLabel(Form)
        self.label.setGeometry(QtCore.QRect(160, 80, 451, 111))
        font = QtGui.QFont()
        font.setPointSize(36)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.btnBack = QtWidgets.QPushButton(Form)
        self.btnBack.setGeometry(QtCore.QRect(210, 250, 261, 71))
        self.btnBack.setObjectName("btnBack")

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        self.label.setText(_translate("Form", "Second screen"))
        self.btnBack.setText(_translate("Form", "Go back"))
