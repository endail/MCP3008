# MCP3008

[![Build on Raspberry Pi](https://github.com/endail/MCP3008/actions/workflows/buildcheck.yml/badge.svg)](https://github.com/endail/MCP3008/actions/workflows/buildcheck.yml) [![cppcheck](https://github.com/endail/MCP3008/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/endail/MCP3008/actions/workflows/cppcheck.yml)

Raspberry Pi C++ API for MCP3008 or MCP3004.

```cpp
MCP3008::MCP3008 adc;
adc.connect();
adc.read(0); //read mcp300x channel 0
```
