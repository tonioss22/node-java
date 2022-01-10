
#include "java.h"
#include "javaObject.h"

extern "C" {
  static void init(v8::Local<v8::Object> exports) {
    Java::Init(exports);
    JavaObject::Init(exports);
  }

  #if (NODE_MAJOR_VERSION >= 10 && NODE_MINOR_VERSION >= 7) || NODE_MAJOR_VERSION >= 11
  NODE_MODULE_INIT() {
    init(exports);
  }
  #else
    NODE_MODULE(nodejavabridge_bindings, init);
  #endif
}

#ifdef WIN32

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
  return TRUE;
}

#endif
