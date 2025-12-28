# VSCode 配置文件说明

本目录包含 VSCode 的 C++ 开发环境配置文件。

## 📁 配置文件列表

### 1. `tasks.json` - 编译任务配置

定义了如何编译 C++ 代码的任务。

#### 主要任务：

**任务 1: C/C++: g++.exe 生成活动文件（默认）**
- 使用 C++20 标准编译
- 生成调试信息（-g）
- 定义 DEBUG_FLAG 宏
- 输出到 `.vscode/exe/` 目录
- 快捷键：`Ctrl+Shift+B`

**任务 2-4: 备用编译任务**
- 简化版编译配置
- 输出到当前目录

#### 关键参数说明：
- `-std=c++20`: 使用 C++20 标准
- `-g`: 生成调试信息
- `-fdiagnostics-color=always`: 彩色错误输出
- `-D DEBUG_FLAG`: 定义调试宏

---

### 2. `launch.json` - 调试配置

定义了如何调试 C++ 程序。

#### 主要功能：

**输入输出重定向**
```json
"args": [
    "<${fileDirname}\\.vscode\\oi\\in.txt",   // 从 in.txt 读取输入
    ">${fileDirname}\\.vscode\\oi\\out.txt"   // 输出到 out.txt
]
```

**调试流程：**
1. 按 `F5` 启动调试
2. 自动执行 `preLaunchTask`（编译任务）
3. 从 `in.txt` 读取输入
4. 运行程序
5. 输出写入 `out.txt`

#### 关键配置：
- `program`: 可执行文件路径
- `args`: 程序参数（输入输出重定向）
- `stopAtEntry`: 是否在入口暂停
- `externalConsole`: 是否使用外部控制台
- `MIMode`: 调试器模式（gdb）

---

### 3. `c_cpp_properties.json` - IntelliSense 配置

配置代码智能提示和语法检查。

#### 主要配置：

**头文件搜索路径**
```json
"includePath": [
    "${workspaceFolder}/**"  // 搜索整个工作区
]
```

**预定义宏**
- `_DEBUG`: 调试模式
- `UNICODE`: Unicode 字符集
- `_UNICODE`: Unicode 字符集（备用）

**语言标准**
- C 标准: `c17`
- C++ 标准: `gnu++20`

---

### 4. `settings.json` - 工作区设置

配置文件关联和编辑器行为。

#### 主要功能：

**文件关联**
- 将 C++ 标准库头文件关联到 C++ 语言模式
- 确保正确的语法高亮和代码补全

---

## 🎯 使用指南

### 编译代码
1. 打开要编译的 `.cpp` 文件
2. 按 `Ctrl+Shift+B` 或选择 `Terminal > Run Build Task`
3. 可执行文件生成在 `.vscode/exe/` 目录

### 调试代码
1. 在 `oi/in.txt` 中准备输入数据
2. 打开要调试的 `.cpp` 文件
3. 按 `F5` 开始调试
4. 查看 `oi/out.txt` 中的输出结果

### 修改配置

#### 更改编译器路径
在 `tasks.json` 和 `c_cpp_properties.json` 中修改：
```json
"command": "你的编译器路径/g++.exe"
"compilerPath": "你的编译器路径/gcc.exe"
```

#### 更改 C++ 标准
在 `tasks.json` 中修改：
```json
"-std=c++20"  // 改为 c++17, c++14 等
```

#### 禁用输入输出重定向
在 `launch.json` 中删除或注释 `args` 配置：
```json
// "args": [
//     "<${fileDirname}\\.vscode\\oi\\in.txt",
//     ">${fileDirname}\\.vscode\\oi\\out.txt"
// ],
```

---

## 📂 目录结构

```
.vscode/
├── tasks.json              # 编译任务配置
├── launch.json             # 调试配置
├── c_cpp_properties.json   # IntelliSense 配置
├── settings.json           # 工作区设置
├── exe/                    # 编译输出目录
│   └── *.exe              # 可执行文件
└── oi/                     # 输入输出文件
    ├── in.txt             # 输入文件
    └── out.txt            # 输出文件
```

---

## 🔧 常见问题

### Q: 编译失败，找不到头文件？
A: 检查 `c_cpp_properties.json` 中的 `includePath` 配置。

### Q: 调试时没有从 in.txt 读取输入？
A: 确保 `launch.json` 中的 `args` 配置正确，且 `in.txt` 文件存在。

### Q: 想要在控制台直接输入而不是从文件读取？
A: 在 `launch.json` 中删除 `args` 配置，并设置 `"externalConsole": true`。

---

**最后更新**: 2025-12-28

