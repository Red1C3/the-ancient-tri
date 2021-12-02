/*
the-ancient-tri A low level OpenGL render engine
Copyright (C) 2021 Mohammad Issawi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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