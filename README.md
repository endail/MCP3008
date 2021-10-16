# MCP3008

[![Build on Raspberry Pi](https://github.com/endail/MCP3008/actions/workflows/buildcheck.yml/badge.svg)](https://github.com/endail/MCP3008/actions/workflows/buildcheck.yml) [![cppcheck](https://github.com/endail/MCP3008/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/endail/MCP3008/actions/workflows/cppcheck.yml)

Raspberry Pi C++ API for MCP3008 or MCP3004.

- Use with Raspberry Pi
- Requires [lgpio](http://abyz.me.uk/lg/index.html)
- Code tested inside [virtual Raspberry Pi Zero/3/4 environments](.github/workflows/buildcheck.yml) on GitHub

```cpp
using namespace MCP3008Lib;
MCP3008 adc;
adc.connect();
adc.read(0); //read mcp300x channel 0
```
