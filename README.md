# vcpkgAndroidTest
安卓+vcpkg测试

## 注意事项：
需在CMakeLists.txt配置以下变量：
```
VCPKG_TARGET_TRIPLET
CMAKE_TOOLCHAIN_FILE
VCPKG_CHAINLOAD_TOOLCHAIN_FILE
```
另外vcpkg.json必须放在build.gradle调用CMakeLists.txt的位置。

限制：

如果使用add_subdirectory引用其它项目，对应的CMakeLists.txt无法通过find_package找到vcpkg的包。（没找到解决方案）
