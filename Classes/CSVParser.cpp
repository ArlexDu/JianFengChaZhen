//
//  CSVParser.cpp
//  MyGame
//
//  Created by arlex on 2020/4/15.
//

#include "CSVParser.hpp"

namespace CSVParser{
    
    Csv::Csv(const string& filename){
    Parse(filename);
    }
    
    Csv::~Csv(){
        
    }
    
    //读取文件内容
    void Csv::Load(const string& filename, string& data){
        auto strPath=FileUtils::getInstance()->fullPathForFilename(filename);
        Data rowData = FileUtils::getInstance()->getDataFromFile(filename);
        unsigned char* cData=NULL;
        cData = rowData.getBytes();
        ssize_t len= rowData.getSize();
        //c. string& assign ( const char* s, size_t n ); 将字符数组或者字符串的首n个字符替换原字符串内容
        data.assign((char*)cData,len);
        rowData.clear();
    }
    
    //解析数据
    void Csv::Parse(const string& filename){
        //清除之前的数据
        m_content.clear();
        m_strErrorInfo.clear();
        
        string text;
        Load(filename,text);
        
        if(text.size()==0){
            return;
        }
        
        //定义状态
        enum StateType{
            NewFieldStart,//新字段开始
            NonQuotesFiled,//非引号字段
            QuotesField,//引号字段
            FieldSeparator,//字段分割
            QuoteInQuotesField,//引号字段中的引号
            RowSeparator,//行分隔符字符1，回车
            Error,//语法错误
        };
        
        Row Fields = Row();
        string strField;
        
        //设置初始状态
        StateType State = NewFieldStart;
        for(int i=0,size=text.size();i<size;++i){
            const char& ch=text[i];
            switch(State){
                case NewFieldStart:{//新字段开始
                    if(ch=='"'){
                        State = QuotesField;
                    }else if(ch==','){
                        Fields.push_back("");
                        State=FieldSeparator;
                    }else if(ch=='\r'||ch=='\n'){
                        m_strErrorInfo="语法错误: 有空行";
                        State=Error;
                    }else{
                        strField.push_back(ch);
                        State=NonQuotesFiled;
                    }
                    break;
                }
                case NonQuotesFiled:{//非引号字段
                    if(ch==','){
                        Fields.push_back(strField);
                        strField.clear();
                        State = FieldSeparator;
                    }else if(ch=='\n'){
                        Fields.push_back(strField);
                        m_content.push_back(Fields);
                        Fields=Row();
                        strField.clear();
                        State = NewFieldStart;
                    }else{
                        strField.push_back(ch);
                    }
                    break;
                }
                case QuotesField:{//引号字段
                    if(ch=='"'){
                        State = QuoteInQuotesField;
                    }else{
                        strField.push_back(ch);
                    }
                    break;
                }
                case FieldSeparator:{//字段分隔
                    if(ch==','){
                        Fields.push_back("");
                    }else if(ch=='"'){
                        strField.clear();
                        State = QuotesField;
                    }else if(ch=='\n'){
                        Fields.push_back("");
                        m_content.push_back(Fields);
                        Fields=Row();
                        strField.clear();
                        State = NewFieldStart;
                    }else{
                        strField.push_back(ch);
                        State = NonQuotesFiled;
                    }
                    break;
                }
                case QuoteInQuotesField:{//引号字段中的引号
                    if(ch==','){//引号字段闭合
                        Fields.push_back(strField);
                        strField.clear();
                        State = FieldSeparator;
                    }else if(ch=='\r'){//引号字段闭合
                        Fields.push_back(strField);
                        State = FieldSeparator;
                    }else if(ch=='"'){//转义
                        strField.push_back(ch);
                        State = QuotesField;
                    }else{
                        m_strErrorInfo="语法错误：转义字符\"不能完成转义或引号字段结尾引号没有紧贴字段分隔符";
                        State = Error;
                    }
                    break;
                }
                case RowSeparator:{//行分隔符字符1，回车
                    if(ch=='\n'){
                        m_content.push_back(Fields);
                        Fields=Row();
                        strField.clear();
                        State = NewFieldStart;
                    }else{
                        m_strErrorInfo="语法错误：行分隔符用了回车\\r。但未使用回车换行符\\r\\n";
                        State = Error;
                    }
                    break;
                }
                case Error:{//语法错误
                    return;
                }
                default:{
                    break;
                }
            }
        }
        
        switch(State){
            case NewFieldStart:{//Excel导出的csv每行都以\r\n结尾。包括最后一行
                break;
            }
            case NonQuotesFiled:{
                Fields.push_back(strField);
                m_content.push_back(Fields);
                break;
            }
            case QuotesField:{
                m_strErrorInfo="语法错误：引号字段未闭合";
                break;
            }
            case FieldSeparator:{
                Fields.push_back("");
                m_content.push_back(Fields);
                break;
            }
            case QuoteInQuotesField:{
                Fields.push_back(strField);
                m_content.push_back(Fields);
                break;
            }
            case RowSeparator:{
                break;
            }
            case Error:{
                break;
            }
            default:{
                break;
            }
        }
        setHeader();
    }
    
    //文件的第一行是header
    void Csv::setHeader(){
        m_header.clear();
        for(unsigned int i=0;i<m_content[0].size();i++){
            m_header.push_back(m_content[0][i]);
        }
        for(unsigned int i=0;i<m_content.size();i++){
            m_content[i].setHeader(&m_header);
        }
    }
    
    Row& Csv::operator[](unsigned int key){
        if(key<m_content.size()){
            return m_content[key];
        }
        throw "can't return this row (doesn't exist)";
    }
    
}
