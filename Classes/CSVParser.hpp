//
//  CSVParser.hpp
//  MyGame
//
//  Created by arlex on 2020/4/15.
//

#ifndef CSVParser_hpp
#define CSVParser_hpp

#include "cocos2d.h"
#include <vector>
#include <string>

using namespace std;
USING_NS_CC;

namespace CSVParser{
    
    //每一行的记录
    class Row{
    public:
        Row(){}
        ~Row(){}
        void push_back(const string& value){
            m_values.push_back(value);
        }
        void setHeader(const vector<string>* header){
            m_header=header;
        }
        
        // 每行数据有多少字段
        //void function(void)const; 编译器会对这个函数进行检查,在这个函数中的任何试图改变成员变量和调用非const成员函数的操作都被视为非法
        unsigned int size() const{return m_values.size();}
        
        //运算符[]重载
        string& operator[](unsigned int key){
            if(key<size()){
                return m_values[key];
            }
            throw "can't return this value (doesn't exist)";
        }
        
        //运算符[]重载
        string& operator[](string& key){
            vector<string>::const_iterator it;
            int pos=0;
            for(it=(*m_header).begin();it!=(*m_header).end();it++){
                if(key==*it){
                    return m_values[pos];
                }
                pos++;
            }
            throw "can't return this value (doesn't exist)";
        }
    private:
        const vector<string>* m_header;
        vector<string> m_values;
    };
    
    class Csv{
    public:
        Csv(const string& filename);
        ~Csv();
        //解析csv文件
        void Parse(const string& filename);
        
        //错误信息
        const string& getErrorInfo() const{
            return m_strErrorInfo;
        }
        
        //获取列头的字段
        vector<string> getHeader() const{
            return m_header;
        }
        
        //获取总行数
        unsigned int getRowCount() const{
            return m_content.size();
        }
        
        //获取总列数
        unsigned int getColumnCount() const{
            return m_header.size();
        }
        
        //重载[]运算符
        Row& operator[](unsigned key);
    
    private:
        
        //读取整个文件数据
        void Load(const string& filename,string& Data);
        void setHeader();
        
    private:
        //所有行的数据
        vector<Row> m_content;
        //列头字段
        vector<string> m_header;
        //错误信息
        string m_strErrorInfo;
    };
    
    
}

#endif /* CSVParser_hpp */
