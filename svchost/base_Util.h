#pragma once

std::string FormatString(const char *lpcszFormat, ...);

std::wstring FormatWstring(const wchar_t *lpcwszFormat, ...);

bool 删除自身();

void 青色打印(const char *内容, ...);

void 黄色打印(const char *内容, ...);

void 粉色打印(const char *内容, ...);

void 红色打印(const char *内容, ...);

void 绿色打印(const char *内容, ...);

void 窗口初始化();

bool EnableDebugPrivilege(bool bEnable);