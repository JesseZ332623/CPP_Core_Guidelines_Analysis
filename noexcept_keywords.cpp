#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

/*
    ͨ������������Ϊ noexcept�����Խ�ֹ�ú����׳��쳣��
    noexcept �ؼ����ڸ��ﾳ����ζ�ţ��Ҳ��ں��쳣��

    ��ԭ������ǣ�����Ա�޷�������쳣������Ӧ����������¾�ֻ�ܵ��� std::terminated() ȥǿ����ֹ����

    ���⣬�������͵ĺ�����Զ����Ҫ���쳣��
        Ĭ�Ϲ��������������� ����
        �ƶ���������
        swap ����
*/

/**
 * @brief �ӱ�׼��������ͨ���Ǽ��̣��ж�ȡ���ݲ���������ַ��� vector �У�
 * �ú��������ڴ�ľ�ʱ������
 * 
 * @param __is ��׼������������
 * 
 * @return �������󷵻ص��ַ��� vector
*/
std::vector<std::string> collect(std::istream & __is) noexcept;

std::vector<std::string> collect(std::istream & __is) noexcept
{
    std::vector<std::string> result;
    
    /*
        ��������������� std::cin�����ض��򵽼��̣�
        ��ѭ����û��ʹ�� break continue �ؼ��ֵĻ�����ѭ��������ѭ����

        ���������һ���ļ� std::ifstream ���߱�ĳ���pipe�������������㹻��ʱ��Ҳ����Ϊ�ڴ�ľ�������
    */
    for (std::string s; std::getline(__is, s);)
    {
        //if (s == "quit") { break; }
        result.push_back(s);
    }

    //while (std::getchar() != '\n') { continue; }
    
    return result;
}

/*��������*/
int main(int argc, char const *argv[])
{
    /*��ֻ��ģʽ��ĳ���ı��ļ�*/
    std::ifstream targetFileRead("./data/target.txt", std::ios_base::in);

    auto showContent = [](const std::string & __s) -> void { std::cout << __s << '\n'; };
    
    /*���ı��ļ��ж�ȡ���ݵ� �ַ���������*/
    std::vector<std::string> stringSetA = collect(targetFileRead);
    //std::vector<std::string> stringSetB = collect(std::cin);

    /*�������*/
    std::for_each(stringSetA.begin(), stringSetA.end(), showContent);
    //std::for_each(stringSetB.begin(), stringSetB.end(), showContent);

    return EXIT_SUCCESS;
}