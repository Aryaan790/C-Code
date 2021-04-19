#include <bits/stdc++.h>

using namespace std;
char input[100][100];
char output[100][100];
string words[100];
vector<string> notFound;
int rows, cols;

string removeSpaces(string word)
{
   word.erase(std::remove(word.begin(), word.end(), ' '), word.end());
   return word;
}

bool searchLeftToRight(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   for (int r = 0; r < rows; r++)
   {
      for (int c = 0; c < cols; c++)
      {
         if (input[r][c] == word[0] && cols - c+1 >= length)
         {
            bool flag = true;
            for (int i = 1; i < length; i++)
            {
               if (input[r][c + i] != word[i])
               {
                  flag = false;
                  break;
               }
            }
            if (flag)
            {
               cout << line << " found at " << r + 1 << ", " << c + 1 << ": (direction = E)\n";
               return true;
            }
         }
      }
   }
   return false;
}

bool searchRightToLeft(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   for (int r = rows - 1; r >= 0; r--)
   {
      for (int c = cols - 1; c >= 0; c--)
      {
         if (input[r][c] == word[0] && c + 1 >= length)
         {
            bool flag = true;
            for (int i = 1; i < length; i++)
            {
               if (input[r][c - i] != word[i])
               {
                  flag = false;
                  break;
               }
            }
            if (flag)
            {
               cout << line << " found at " << r + 1 << ", " << c + 1 << ": (direction = W)\n";
               return true;
            }
         }
      }
   }
   return false;
}

bool searchUpToDown(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   for (int c = 0; c < cols; c++)
   {
      for (int r = 0; r < rows; r++)
      {
         if (input[r][c] == word[0] && rows - r + 1 >= length)
         {
            bool flag = true;
            for (int i = 1; i < length; i++)
            {
               if (input[r + i][c] != word[i])
               {
                  flag = false;
                  break;
               }
            }
            if (flag)
            {
               cout << line << " found at " << r + 1 << ", " << c + 1 << ": (direction = S)\n";
               return true;
            }
         }
      }
   }
   return false;
}

bool searchDownToUp(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   for (int c = cols - 1; c >= 0; c--)
   {
      for (int r = rows - 1; r >= 0; r--)
      {
         if (input[r][c] == word[0] && r+1 >= length)
         {
            bool flag = true;
            for (int i = 1; i < length; i++)
            {
               if (input[r - i][c] != word[i])
               {
                  flag = false;
                  break;
               }
            }
            if (flag)
            {
               cout << line << " found at " << r + 1 << ", " << c + 1 << ": (direction = N)\n";
               return true;
            }
         }
      }
   }
   return false;
}

bool searchLeftUpToRightDown(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   for (int r = 0; r < rows; r++)
   {
      for (int c = 0; c < cols; c++)
      {
         if (input[r][c] == word[0] && cols - c +1 >= length && rows - r+1 >= length)
         {
            bool flag = true;
            for (int i = 1; i < length; i++)
            {
               if (input[r + i][c + i] != word[i])
               {
                  flag = false;
                  break;
               }
            }
            if (flag)
            {
               cout << line << " found at " << r + 1 << ", " << c + 1 << ": (direction = SE)\n";
               return true;
            }
         }
      }
   }
   return false;
}

bool searchRightDownToLeftUp(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   for (int r = rows-1; r >= 0; r--)
   {
      for (int c = cols-1; c >= 0; c--)
      {
         if (input[r][c] == word[0] && c+1 >= length && r+1 >= length)
         {
            bool flag = true;
            for (int i = 1; i < length; i++)
            {
               if (input[r - i][c - i] != word[i])
               {
                  flag = false;
                  break;
               }
            }
            if (flag)
            {
               cout << line << " found at " << r + 1 << ", " << c + 1 << ": (direction = NW)\n";
               return true;
            }
         }
      }
   }
   return false;
}

bool searchRightUpToLeftDown(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   for (int r = 0; r < rows; r++)
   {
      for (int c = cols-1; c >= 0; c--)
      {
         if (input[r][c] == word[0] && c+1 >= length && rows - r+1 >= length)
         {
            bool flag = true;
            for (int i = 1; i < length; i++)
            {
               if (input[r + i][c - i] != word[i])
               {
                  flag = false;
                  break;
               }
            }
            if (flag)
            {
               cout << line << " found at " << r + 1 << ", " << c + 1 << ": (direction = SW)\n";
               return true;
            }
         }
      }
   }
   return false;
}

bool searchLeftDownToRightUp(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   for (int r = rows-1; r >= 0; r--)
   {
      for (int c = 0; c < cols; c++)
      {
         if (input[r][c] == word[0] && cols - c+1 >= length && r+1 >= length)
         {
            bool flag = true;
            for (int i = 1; i < length; i++)
            {
               if (input[r - i][c + i] != word[i])
               {
                  flag = false;
                  break;
               }
            }
            if (flag)
            {
               cout << line << " found at " << r + 1 << ", " << c + 1 << ": (direction = NE)\n";
               return true;
            }
         }
      }
   }
   return false;
}

bool findWord(string line)
{
   string word = removeSpaces(line);
   int length = word.length();
   bool found = false;
   if (length > rows && length > cols)
      return found;
   else if (length <= rows && length <= cols)
   {
      if (searchLeftToRight(word))
         found = true;
      if (searchRightToLeft(word))
         found = true;
      if (searchUpToDown(word))
         found = true;
      if (searchDownToUp(word))
         found = true;
      if (searchLeftUpToRightDown(word))
         found = true;
      if (searchRightDownToLeftUp(word))
         found = true;
      if (searchRightUpToLeftDown(word))
         found = true;
      if (searchLeftDownToRightUp(word))
         found = true;
   }
   else if (length > rows && length <= cols)
   {
      if (searchLeftToRight(word))
         found = true;
      if (searchRightToLeft(word))
         found = true;
   }
   else
   {
      if (searchUpToDown(word))
         found = true;
      if (searchDownToUp(word))
         found = true;
   }
   return found;
}

int main()
{
   ifstream finput;
   string fileDirectory = "comedy_full.txt";
   cout << "Opening file : " << fileDirectory << "\n";
   finput.open("comedy_full.txt");

   while (!finput)
   {
      perror("FILE NOT FOUND! ");
      string exit = "exit", quit = "quit";
      cout << "Enter other file location (or 'quit' | 'exit' to quit) : ";
      cin >> fileDirectory;
      if (fileDirectory.compare(exit) == 0 || fileDirectory.compare(quit) == 0)
      {
         cout << "Quitting...\n";
         return 0;
      }
      cout << "Opening file : " << fileDirectory << "\n";
      finput.open("comedy_full.txt");
   }
   cout << "FILE OPENED\n";
   string line;
   while (getline(finput, line))
   {
      if (line[0] != '#' && !line.empty())
      {
         stringstream row(line);
         row >> rows;
         row >> cols;
         break;
      }
   }

   int r = 0;
   while (getline(finput, line) && r < rows)
   {
      if (line[0] != '#' && !line.empty())
      {
         for (int c = 0; c < cols; c++)
         {
            input[r][c] = line[c];
         }
         r++;
      }
   }

   cout << "\n\nMOVIES FOUND\n\n";
   while (getline(finput, line))
   {
      if (line[0] != '#' && !line.empty())
      {
         bool found = findWord(line);
         if (!found)
         {
            notFound.push_back(line);
         }
      }
   }

   cout << "\n\nMOIVES NOT FOUND!\n\n\t";
   for (int i = 0, s = notFound.size(); i < s; i++)
      cout << notFound[i] << "\n\t";

   return 0;
}
