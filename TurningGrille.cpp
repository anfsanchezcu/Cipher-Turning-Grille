#include <bits/stdc++.h>
#include <string>

using namespace std;

pair<int, int> rotation(int a, int b, int dimention, bool rot)
{
  --dimention;
  int x;
  int y;
  if (rot == false)
  {
    x = dimention - b;
    y = a;
  }
  else
  {
    x = b;
    y = dimention - a;
  }
  return make_pair(x, y);
}

void rotatePoints(vector<pair<int, int>> &points, int dimention, bool rot)
{ 
  vector<pair<int, int>> r;
  for (pair<int, int> point : points)
    r.push_back(rotation(point.first, point.second, dimention, rot));

  sort(r.begin(), r.end());
  points = r;
}
string fillSpaces(int n)
{
  string stringAux;
  for (int i = 0; i < n; i++)
    stringAux += "x";
  return stringAux;
}

string getString(vector<string> &grid, vector<pair<int, int>> &points)
{
  string r = "";
  for (pair<int, int> p : points)
    r += grid[p.first][p.second];
  return r;
}
void removeSpaces(string &str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}
void putValues(vector<string> &grid, vector<pair<int, int>> &points, string &text)
{
  for (pair<int, int> p : points)
  { 
    grid[p.first][p.second] = text[0];
    text = text.substr(1);
  }
}

void Cipher(int length, int direction, vector<string> &grid, vector<pair<int, int>> &points)
{
  string text,aux;
  cin >>ws;
  getline(cin, text);
  //removemos espacio del texto
  removeSpaces(text);

  // proceso de encriptado o desencriptado
  for (int i = 0; i < 4; i++)
  {
    putValues(grid, points, text);
    rotatePoints(points, length, direction != -1);
  }

  for (string t : grid)
    cout << t << endl;
}

void Decrypt(int length, int direction, vector<string> &grid, vector<pair<int, int>> &points)
{
  string aux;
  for (int i = 0; i < length; i++)
  {
    cin >> aux;
    grid[i] = aux;
  }

  // proceso de encriptado o desencriptado
  aux = "";
  for (int i = 0; i < 4; i++)
  {
    aux += getString(grid, points) + " ";
    rotatePoints(points, length, direction != -1);
  }
  cout << aux << endl;
}

int main()
{
  // optencion de datos
  int l, h, direction, mode;
  cin >> l >> h >> direction >> mode;

  vector<string> grid(l, fillSpaces(l));
  vector<pair<int, int>> points;

  int positions, a, b;
  cin >> positions;
  for (int i = 0; i < positions; i++)
  {
    cin >> a >> b;
    points.push_back(make_pair(a, b));
  }
  sort(points.begin(), points.end());

  if (mode == 1)
    Decrypt(h, direction, grid, points);
  else
    Cipher(h, direction, grid, points);

  return 0;
}
