#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class FileSystem{

private:                                //But Y Private

    unordered_map<string,set<string>> directories;  //This is beacause two files cannot have same file name and there must be mapping between them ie current directory paths and sub directories
    unordered_map<string,string> files//To Map "file path" to "file"

    //We are using unordered map because they are highly efficient and we have  best case read and write
public:  //Y public

    //https://www.geeksforgeeks.org/constructors-c/
    //Creating root directory using constructors
    FileSystem()
    {
        directories["/"];
    }


    //ls -> This function will return all the files in a given path if existed and subdirectories.
    // As we have to retuen all files in the current directory ie vector of strings,Input is of course a path

    vector<string> ls(string path)
    {
        if(files.count(path)) //Check if there is a file path already that corresponds to this path If yes
        {
            int idx = path.find_last_of('/');
            return {path.substr(idx+1)}; //return whatever is present after idx that string as it will be the only file xD
        }

        auto t = directories[path]; //Normal case when it corresponds to directory
        return vector<string>(t.begin(),t.end());
    }

    //Done LS

    void MakeDirectory(string path) //No need to create anything just create file at that path
    {
        istringstream is(path);                 //https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
        string CurrentDirectory = "";
        string DirectoyPathNow = "";

        while(getline(is, CurrentDirectory, '/'))  //Here cd splits is into diff parts by '/' and at each time it takes one
        {
            if(CurrentDirectory.empty())
                continue;

            if(DirectoryPathNow.empty())
                DirectoryPathNow += "/";   //Describing root directory

            directories.[DirectoryPathNow].insert(CurrentDirectory);

            if(DirectoryPathNow.size() > 1) //Except for the first case NOTE > 1 xD
                DirectoryPathNow += "/";   //Other than root for all remaining

            DirectoryPathNow += CurrentDirectory;
        }
    }

    void AddSomethingToFile(string FilePath, string content)
    {
        int IndexOfLast = FilePath.find_last_of('/');
        string DirectoryPath = Filepath.substr(0, IndexOfLast);
        string file = FilePath.substr(IndexOfLast+1);

        if(DirectoryPath.empty())
            DirectoryPath = "/";

        if(!directories.count(DirectoryPath))
            MakeDirectory(DirectoryPath);

            directories[DirectoryPath].insert(file);
            files[FilePath].append(content);

    }
};

int main()
{
    FileSystem obj;

    obj.MakeDirectory("/TestA");
    obj.MakeDirectory("/TestB");

    /*vector<string>:: iterator i;
    vector<string>l = obj.ls("/shan");

     for (i = l.begin(); i != l.end(); ++i)
        cout << *i << '\t';

    AddSomethingToFile("/shan/Documents/exm.txt", "I love code");

    string f = ReadFile("/shan/Documents/exm.txt");
    cout<<endl<<f<<endl;

     */
    return 0;


}


