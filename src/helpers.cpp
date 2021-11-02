#include <helpers.h>
using namespace tat;
using namespace std;
vector<char> tat::readBinaryFile(const char *path)
{
    fstream fileStream(path, ios::in | ios::binary | ios::ate);
    vector<char> data;
    assert(fileStream.is_open());
    int size = fileStream.tellg();
    fileStream.seekg(0, ios::beg);
    data.resize(size);
    fileStream.read(data.data(), data.size());
    fileStream.flush();
    fileStream.close();
    return data;
}