#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <cassert>

int main(int argc, char** argv)
{
  assert(argc == 2);

  HANDLE h = CreateFileA(argv[1], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  assert(h != INVALID_HANDLE_VALUE);

  HANDLE m = CreateFileMappingA(h, 0, PAGE_READONLY, 0, 0, NULL);
  assert(m != INVALID_HANDLE_VALUE);

  const void * ptr = MapViewOfFile(m, FILE_MAP_READ, 0, 0, 0);
  assert(ptr != nullptr);

  UnmapViewOfFile(ptr);

  CloseHandle(m);

  CloseHandle(h);
  return 0;
}

