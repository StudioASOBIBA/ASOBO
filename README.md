# ASOBO

ASOBO - Multi-platform 3D/2D Game Runtime Library & Editor

A cross-platform game development library and editor written in C/C++, supporting Windows, Linux, and macOS.

## Features

- **Multi-platform Support**: Windows, Linux, macOS
- **Modular Architecture**: Runtime library and editor application
- **Graphics API Abstraction**: Support for OpenGL, Vulkan, DirectX, Metal
- **CMake Build System**: Modern, cross-platform build configuration
- **IDE Support**: Pre-configured for Visual Studio, VS Code, and CLion

## Project Structure

```
ASOBO/
├── include/           # Public header files
│   └── asobo/
│       ├── core.h     # Core runtime API
│       └── graphics.h # Graphics subsystem API
├── runtime/           # Runtime library source
│   ├── src/
│   └── CMakeLists.txt
├── editor/            # Editor application
│   ├── src/
│   └── CMakeLists.txt
├── examples/          # Example programs
├── tests/             # Unit tests
├── .vscode/           # VS Code configuration
└── CMakeLists.txt     # Root CMake configuration
```

## Requirements

### Build Tools
- CMake 3.20 or higher
- C11 compatible C compiler
- C++17 compatible C++ compiler

### Supported Compilers
- GCC 7.0+
- Clang 5.0+
- MSVC 2017+

### Supported IDEs
- Visual Studio 2017 or later
- Visual Studio Code with CMake Tools extension
- CLion 2020.1 or later

## Building from Source

### Using CMake (Command Line)

#### Configure
```bash
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
```

#### Build
```bash
cmake --build build --config Release
```

#### Install
```bash
cmake --install build --prefix /usr/local
```

### Build Options

- `ASOBO_BUILD_RUNTIME` - Build runtime library (default: ON)
- `ASOBO_BUILD_EDITOR` - Build editor application (default: ON)
- `ASOBO_BUILD_TESTS` - Build tests (default: ON)
- `ASOBO_BUILD_EXAMPLES` - Build examples (default: ON)

Example:
```bash
cmake -B build -DASOBO_BUILD_TESTS=OFF -DASOBO_BUILD_EXAMPLES=OFF
```

### Platform-Specific Instructions

#### Linux
```bash
# Install build dependencies (Ubuntu/Debian)
sudo apt-get install build-essential cmake

# Build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

#### macOS
```bash
# Install build dependencies
brew install cmake

# Build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

#### Windows
```bash
# Using Visual Studio 2019/2022
cmake -B build -G "Visual Studio 16 2019"
cmake --build build --config Release

# Or open ASOBO.sln in Visual Studio
```

## Using with IDEs

### Visual Studio Code

1. Install recommended extensions:
   - C/C++ Extension Pack
   - CMake Tools

2. Open the project folder in VS Code

3. Configure CMake:
   - Press `Ctrl+Shift+P` (or `Cmd+Shift+P` on macOS)
   - Select "CMake: Configure"

4. Build:
   - Press `Ctrl+Shift+P`
   - Select "CMake: Build"
   - Or press `F7`

5. Run/Debug:
   - Use the Run and Debug panel (Ctrl+Shift+D)
   - Select a launch configuration
   - Press F5

### CLion

1. Open the project folder in CLion
2. CLion will automatically detect the CMake project
3. Select build configuration from the dropdown
4. Build using `Ctrl+F9` (or `Cmd+F9` on macOS)
5. Run using `Shift+F10` (or `Ctrl+R` on macOS)

### Visual Studio

1. Open Visual Studio
2. File → Open → CMake...
3. Select the root `CMakeLists.txt`
4. Visual Studio will configure the project
5. Build using `Ctrl+Shift+B`
6. Run using `Ctrl+F5`

## Running Tests

```bash
# Build tests
cmake --build build

# Run tests
ctest --test-dir build --output-on-failure
```

## Running Examples

```bash
# After building
./build/bin/examples/basic-example
```

## Running the Editor

```bash
# After building
./build/bin/asobo-editor
```

## API Usage

### Basic Initialization

```c
#include <asobo.h>

int main(void) {
    // Initialize runtime
    if (asobo_init() != 0) {
        return 1;
    }
    
    // Initialize graphics
    asobo_graphics_init(ASOBO_GRAPHICS_API_OPENGL);
    
    // Your game/application code here
    asobo_graphics_clear(0.0f, 0.0f, 0.0f, 1.0f);
    
    // Cleanup
    asobo_graphics_shutdown();
    asobo_shutdown();
    
    return 0;
}
```

## Contributing

Contributions are welcome! Please ensure your code:
- Follows the existing code style
- Includes appropriate tests
- Builds successfully on all platforms

## License

See LICENSE file for details.
