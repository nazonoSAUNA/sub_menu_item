#include <windows.h>
#include <filter.h>

FILTER_DLL filter_dll = {
    FILTER_FLAG_ALWAYS_ACTIVE | FILTER_FLAG_NO_CONFIG,
    NULL,NULL,const_cast<char*>("sub_menu_item"),
};
BOOL replace_data(DWORD* address, DWORD data) {
    DWORD oldProtect;
    if (!VirtualProtect(address, 4, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        return FALSE;
    }
    *address = data;
    return VirtualProtect(address, 4, oldProtect, &oldProtect);
}
FILTER* get_thisfp(FILTER* fp) {
    SYS_INFO si;
    fp->exfunc->get_sys_info(NULL, &si);
    for (int i = si.filter_n - 1; 0 <= i; i--) {
        fp = (FILTER*)fp->exfunc->get_filterp(i);
        if (fp->name != NULL) {
            if (!lstrcmpA(fp->name, filter_dll.name)) {
                return fp;
            }
        }
    }
    return NULL;
}

char str[256];
FILTER* this_fp = NULL;
BOOL(__cdecl* add_menu_item)(FILTER* fp, LPSTR name, HWND hwnd, int id, int def_key, int flag);
BOOL __cdecl add_menu_item_wrap(FILTER* fp, LPSTR name, HWND hwnd, int id, int def_key, int flag) {
    if (this_fp == NULL) {
        this_fp = get_thisfp(fp);
    }
    if (this_fp != NULL) {
        wsprintfA(str, "%s_%s", fp->name, name);
        int inival = fp->exfunc->ini_load_int(this_fp, str, -1);
        if (inival == 0) {
            return FALSE;
        }
        if (inival == -1) {
            fp->exfunc->ini_save_int(this_fp, str, 1);
        }
    }
    return add_menu_item(fp, name, hwnd, id, def_key, flag);
}
EXTERN_C FILTER_DLL __declspec(dllexport)* __stdcall GetFilterTable() {
    DWORD aviutl_hinst = (DWORD)GetModuleHandleA(NULL);
    if (*reinterpret_cast<short*>(aviutl_hinst + 0x2d116) == 0x05c7 && *reinterpret_cast<short*>(aviutl_hinst + 0x2d120) == 0x05c7 && *reinterpret_cast<short*>(aviutl_hinst + 0x2d12a) == 0x05c7) {
        (add_menu_item) = (*reinterpret_cast<decltype(add_menu_item)*>(aviutl_hinst + 0x2d126));
        replace_data((DWORD*)(aviutl_hinst + 0x2d126), (DWORD)&add_menu_item_wrap);
    } else {
        MessageBoxA(NULL, "AviUtl ver1.10‚Ì‚Ý‘Î‰ž‚Å‚·", filter_dll.name, MB_OK);
    }
    return &filter_dll;
}