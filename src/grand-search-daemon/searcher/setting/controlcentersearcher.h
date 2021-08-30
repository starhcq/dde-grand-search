/*
 * Copyright (C) 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     zhangyu<zhangyub@uniontech.com>
 *
 * Maintainer: zhangyu<zhangyub@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef CONTROLCENTERSEARCHER_H
#define CONTROLCENTERSEARCHER_H

#include "searcher/searcher.h"

class ControlCenterSearcherPrivate;
class ControlCenterSearcher : public Searcher
{
    Q_OBJECT
    friend class ControlCenterSearcherPrivate;
public:
    explicit ControlCenterSearcher(QObject *parent = nullptr);
    ~ControlCenterSearcher();
    void asyncInit();
    QString name() const Q_DECL_OVERRIDE;
    bool isActive() const Q_DECL_OVERRIDE;
    bool activate() Q_DECL_OVERRIDE;
    ProxyWorker *createWorker() const Q_DECL_OVERRIDE;
    bool action(const QString &action, const QString &item) Q_DECL_OVERRIDE;
private:
    ControlCenterSearcherPrivate *d;
};

#endif // CONTROLCENTERSEARCHER_H
