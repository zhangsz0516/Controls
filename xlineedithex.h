// copyright (c) 2017-2019 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef XLINEEDITHEX_H
#define XLINEEDITHEX_H

#include <QLineEdit>
#include <QVariant>
#include <QMenu>
#include <QAction>

class XLineEditHEX : public QLineEdit
{
    Q_OBJECT
public:
    explicit XLineEditHEX(QWidget *parent=nullptr);
    void setValue(quint8 value);
    void setValue(qint8 value);
    void setValue(quint16 value);
    void setValue(qint16 value);
    void setValue(quint32 value);
    void setValue(qint32 value);
    void setValue(quint64 value);
    void setValue(qint64 value);
    void setValue32_64(quint64 value);
    void setStringValue(QString sText, qint32 nMaxLength=0);
    quint64 getValue();

private slots:
    void _setText(QString sText);
    void customContextMenu(const QPoint &pos);

signals:
    void valueChanged(quint64 nValue);

private:
    quint64 nValue;
};

#endif // XLINEEDITHEX_H