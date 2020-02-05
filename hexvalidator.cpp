// copyright (c) 2017-2020 hors<horsicq@gmail.com>
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
#include "hexvalidator.h"

HEXValidator::HEXValidator(QObject *parent) : QValidator(parent)
{
    _mode=MODE_HEX;
    _nMax=0xFFFFFFFFFFFFFFFF;
}

void HEXValidator::setData(HEXValidator::MODE mode, quint64 nMax)
{
    _mode=mode;
    _nMax=nMax;
}

HEXValidator::MODE HEXValidator::getMode()
{
    return _mode;
}

QValidator::State HEXValidator::validate(QString &input, int &pos) const
{
    Q_UNUSED(pos)

    QValidator::State result=Acceptable;

    if(!input.isEmpty())
    {
        if(_mode==MODE_HEX)
        {
            result=Invalid;

            bool bSuccess=false;
            quint64 nValue=0;

            nValue=input.toULongLong(&bSuccess,16);

            if(bSuccess&&(nValue<=_nMax))
            {
                result=Acceptable;
            }
        }
    }

    return result;
}
