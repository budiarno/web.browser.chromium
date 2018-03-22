#pragma once
/*
 *      Copyright (C) 2015-2017 Team KODI
 *      http:/kodi.tv
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "include/cef_render_handler.h"

#include "IRenderer.h"
#include "shaders/GUIShader.h"

class CWebBrowserClient;

class ATTRIBUTE_HIDDEN CRendererClientOpenGL : public IRenderer
{
public:
  CRendererClientOpenGL(CWebBrowserClient const* client);
  virtual ~CRendererClientOpenGL();

  virtual bool Initialize() override;
  virtual void Render() override;
  virtual void ScreenSizeChange(float x, float y, float width, float height) override;

private:
  unsigned int m_textureId;
  int m_viewWidth;
  int m_viewHeight;
  CefRect m_popupRect;
  CefRect m_updateRect;
  CGUIShader *m_shader = nullptr;
};