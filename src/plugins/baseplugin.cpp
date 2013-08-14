/*
 * Copyright (C) 2013 Simon Busch <morphis@gravedo.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include "baseplugin.h"
#include "webapplication.h"

namespace luna
{

BasePlugin::BasePlugin(const QString &name, WebApplication *application, QObject *parent) :
    QObject(parent),
    mApplication(application),
    mName(name)
{
}

QString BasePlugin::name() const
{
    return mName;
}

void BasePlugin::callback(int id, const QString &parameters)
{
    QString script;

    if (parameters.length() > 0) {
        script = QString("webOS.callback(%1, %2);").arg(id).arg(parameters);
    }
    else {
        script = QString("webOS.callback(%1);").arg(id);
    }

    mApplication->executeScript(script);
}

void BasePlugin::callbackWithoutRemove(int id, const QString &parameters)
{
    QString script;

    if (parameters.length() > 0) {
        script = QString("webOS.callbackWithoutRemove(%1, %2);").arg(id).arg(parameters);
    }
    else {
        script = QString("webOS.callbackWithoutRemove(%1);").arg(id);
    }

    mApplication->executeScript(script);
}

} // namespace luna