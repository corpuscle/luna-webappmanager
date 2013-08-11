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

#include "webappmanager.h"
#include "webappmanagerservice.h"

namespace luna
{

WebAppManager::WebAppManager(int &argc, char **argv)
    : QGuiApplication(argc, argv),
      mMainLoop(0),
      mService(0)
{
    setApplicationName("luna-webappmanager");

    mMainLoop = g_main_loop_new(g_main_context_default(), TRUE);

    mService = new WebAppManagerService(mMainLoop);
}

WebAppManager::~WebAppManager()
{
    delete mService;
    g_main_loop_unref(mMainLoop);
}

} // namespace luna
