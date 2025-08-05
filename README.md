# libcocoa

macOS Cocoa フレームワーク用のCラッパーライブラリです。`objc_msgSend`を使ってCプログラムからSwift/Objective-Cの機能を呼び出すことができます。

## 概要

libcocoaは、macOS Cocoaフレームワーク用のC言語バインディングを提供し、開発者がC言語を使ってネイティブmacOSアプリケーションを作成できるようにします。CoreFoundation、CoreGraphics、AppKitの機能をクリーンなC APIでラップしています。

## ステータス

🚧 **初期開発段階** - 基本機能は実装済み、APIは変更される可能性があります。

## システム要件

- macOS（CocoaフレームワークはmacOS専用）  
- CMake 3.10以降
- C99対応コンパイラ

## ビルド方法

```bash
mkdir build && cd build
cmake ..
make
```

## 使用方法

```c
#include <libcocoa/libcocoa.h>

int main() {
    id pool = NSAutoreleasePool_new();
    
    id app = NSApplication_sharedApplication();
    NSApplication_setActivationPolicy(app, NSApplicationActivationPolicyRegular);
    
    id mainMenu = NSMenu_createApplicationMenu("My App");
    NSApplication_setMainMenu(app, mainMenu);
    NSApplication_finishLaunching(app);
    
    CGRect rect = CGRectMake(300, 300, 400, 200);
    id window = NSWindow_alloc();
    window = NSWindow_initWithContentRect(window, rect, 
        NSWindowStyleMaskTitled | NSWindowStyleMaskClosable, 
        NSBackingStoreBuffered, NO);
    
    NSWindow_setTitle(window, NSString_stringWithUTF8String("Hello libcocoa"));
    NSWindow_makeKeyAndOrderFront(window, nil);
    NSApplication_activateIgnoringOtherApps(app, YES);
    
    NSApplication_run(app);
    
    NSAutoreleasePool_drain(pool);
    return 0;
}
```

## プロジェクト構造

```text
libcocoa/
├── include/libcocoa/     # パブリックヘッダー
│   ├── common/          # 共通型とユーティリティ
│   ├── corefoundation/  # CoreFoundationラッパー
│   ├── coregraphics/    # CoreGraphicsラッパー
│   └── appkit/          # AppKitラッパー
├── src/                 # 実装ファイル
├── examples/            # サンプルアプリケーション
└── tests/               # ユニットテスト
```

## サンプル

ビルド後、以下のコマンドでサンプルを実行できます：

```bash
./examples/minimal_window
./examples/simple_window
./examples/button_example
```

## ライセンス

詳細は [LICENSE](LICENSE) ファイルを参照してください。
