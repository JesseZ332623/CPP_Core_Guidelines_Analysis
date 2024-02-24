#include <stdio.h>
#include <string>

#include <stdexcept>

class FileDisk
{
    private:
        FILE * filePointer;
        bool valid;

    public:
        FileDisk(const std::string & __filePath) : filePointer(fopen(__filePath.c_str(), "r")), valid(false) 
        {
            /*
                如果出现打开文件失败的情况，直接抛异常，
                这里的处理比较直接，工作中不会这么用。
            */
            if (!filePointer) { throw std::invalid_argument("Invalid File Path!"); }

            valid = true;
        }

        /*低效！*/
        bool inValid() { return (valid == true); }

        ~FileDisk() { fclose(filePointer); }
};