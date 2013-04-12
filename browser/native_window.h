// Copyright (c) 2013 GitHub, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_NATIVE_WINDOW_H_
#define ATOM_BROWSER_NATIVE_WINDOW_H_

#include <iosfwd>

#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "base/memory/scoped_ptr.h"

namespace base {
class DictionaryValue;
}

namespace brightray {
class InspectableWebContents;
}

namespace content {
class BrowserContext;
class WebContents;
}

namespace gfx {
class Point;
class Rect;
class Size;
}

namespace atom {

class NativeWindow {
 public:
  virtual ~NativeWindow();

  static NativeWindow* Create(content::BrowserContext* browser_context,
                              base::DictionaryValue* options);

  void InitFromOptions(base::DictionaryValue* options);

  virtual void Close() = 0;
  virtual void Move(const gfx::Rect& pos) = 0;
  virtual void Focus(bool focus) = 0;
  virtual void Show() = 0;
  virtual void Hide() = 0;
  virtual void Maximize() = 0;
  virtual void Unmaximize() = 0;
  virtual void Minimize() = 0;
  virtual void Restore() = 0;
  virtual void SetFullscreen(bool fullscreen) = 0;
  virtual bool IsFullscreen() = 0;
  virtual void SetSize(const gfx::Size& size) = 0;
  virtual gfx::Size GetSize() = 0;
  virtual void SetMinimumSize(int width, int height) = 0;
  virtual void SetMaximumSize(int width, int height) = 0;
  virtual void SetResizable(bool resizable) = 0;
  virtual void SetAlwaysOnTop(bool top) = 0;
  virtual void SetPosition(const std::string& position) = 0;
  virtual void SetPosition(const gfx::Point& position) = 0;
  virtual gfx::Point GetPosition() = 0;
  virtual void SetTitle(const std::string& title) = 0;
  virtual void FlashFrame(bool flash) = 0;
  virtual void SetKiosk(bool kiosk) = 0;
  virtual bool IsKiosk() = 0;
  virtual void ShowDevTools();
  virtual void CloseDevTools();

  content::WebContents* GetWebContents() const;

 protected:
  explicit NativeWindow(content::BrowserContext* browser_context,
                        base::DictionaryValue* options);

  brightray::InspectableWebContents* inspectable_web_contents() const {
    return inspectable_web_contents_.get();
  }

 private:
  scoped_ptr<brightray::InspectableWebContents> inspectable_web_contents_;

  DISALLOW_COPY_AND_ASSIGN(NativeWindow);
};

}  // namespace atom

#endif  // ATOM_BROWSER_NATIVE_WINDOW_H_
