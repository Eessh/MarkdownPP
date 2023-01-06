# MarkdownPP
[Header](https://github.com/Eessh/MarkdownPP/blob/master/MarkdownParser.hpp) only library for parsing markdown to Abstract Syntax Tree (AST).

### Build
- Sublime Text
  - Install [Premake5](https://premake.github.io/)
  - If you have Sublime Text installed, you could just open `MarkdownPP.sublime-project` with Sublime Text, and set Build System to `Project Build System`. The build and run commands can be accessed with shortcut `(Ctrl/Command)+Shift+b`.
  
    ![SublimeProjectBuildSystem](./screenshots/SublimeProjectBuildSystem.png)

- Command Line
  - Windows
    - Generate Makefiles using Premake5
      ```powershell
      (project root dir) $ .\scripts\windows\gen_makefiles.bat
      ```
    - Build Debug version
      ```powershell
      (project root dir) $ .\scripts\windows\build_debug.bat
      ```
      This will place the executable in `.\bin\Debug\`
    - Build Release version
      ```powershell
      (project root dir) $ .\scripts\windows\build_release.bat
      ```
      This will place the executable in `.\bin\Release\`
    - Build TestBuilder
      ```powershell
      (project root dir) $ .\scripts\windows\build_testbuilder.bat
      ```
    - Run Debug Version
      ```powershell
      (project root dir) $ .\scripts\windows\run_debug.bat
      ```
    - Run Release Verison
      ```powershell
      (project root dir) $ .\scripts\windows\run_release.bat
      ```
    - Run Tests
      ```powershell
      (project root dir) $ .\scripts\windows\run_tests.bat
      ```
    - Clean project
      ```powershell
      (project root dir) $ .\scripts\windows\clean.bat
      ```
  - Unix (Linux & macOS)
    - Install [Premake5](https://premake.github.io/)
    - For Linux, use scripts in linux folder `./scripts/linux/`
    - For macOS, use scripts in macos folder `./scripts/macos/`
    - Generate Makefiles using Premake5
      ```sh
      (project root dir) $ ./scripts/(linux or macos)/gen_makefiles.sh
      ```
    - Build Debug version
      ```sh
      (project root dir) $ ./scripts/(linux or macos)/build_debug.sh
      ```
      This will place the executable in `./bin/Debug/`
    - Build Release version
      ```sh
      (project root dir) $ ./scripts/(linux or macos)/build_release.sh
      ```
      This will place the executable in `./bin/Release/`
    - Build TestBuilder
      ```sh
      (project root dir) $ ./scripts/(linux or macos)/build_testbuilder.sh
      ```
    - Run Debug Version
      ```sh
      (project root dir) $ ./scripts/(linux or macos)/run_debug.sh
      ```
    - Run Release Verison
      ```sh
      (project root dir) $ ./scripts/(linux or macos)/run_release.sh
      ```
    - Run Tests
      ```sh
      (project root dir) $ ./scripts/(linux or macos)/run_tests.sh
      ```
    - Clean project
      ```sh
      (project root dir) $ ./scripts/(linux or macos)/clean.sh
      ```


### Credits
Thanks to [Aaron Fu Lei](https://github.com/aafulei) for his [color-console](https://github.com/aafulei/color-console). It helped me move from printing boring white to colorful Test Logs.
