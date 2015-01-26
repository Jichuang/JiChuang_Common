//
//  main.swift
//  SwiftOOP
//
//  Created by Hope6537 on 15-1-13.
//  Copyright (c) 2015�� Hope6537. All rights reserved.
//

import Foundation

class People{
    var name : String = "";
    var apperance : String = "";
    var dream : String = "";
    var reality : String = "";
    //���Թ۲���ģʽ
    var lover : People?{
        //���Ըı�ǰ����
        willSet(newLover){
            if(self.lover != nil){
                if(newLover != nil){
                    println("\(self.name) lover has changed to \(newLover)");
                }
            }
            else{
                if(newLover != nil){
                    println("\(self.name) has found first love  \(newLover)");
                }
            }
        }
        //���Ըı�󴥷�
        didSet(oldLover){
            if(oldLover != nil){
                println("\(self.name) has left the oldlover \(oldLover)");
            }
        }
    };
    //��������
    var isHappy : Bool{
        get{
            if(dream != "" && dream == reality || lover != nil || apperance == "handsome"){
                return true;
            }else{
                return false;
            }
        }
        set{
            if(newValue == true){
                apperance = "handsome";
            }else{
                apperance = "pool";
            }
        }
    }
    //������������� �����е�People����������
    class var plannet : String{
        //ͬ������дset��get
        get{
            return "����";
        }
        set{
     
        }
    }
    class var staticParam : String{
        return "��̬����";
    }
    class func staticFunc(){
        println("��̬����");
        println(staticParam);
    }
}

var oldCoder = People();
println("Old Coder is Happy :\(oldCoder.isHappy)");
oldCoder.isHappy = true;
println("app : \(oldCoder.apperance)");
println(People.plannet);

//���Թ۲���֮ȫ�ֱ���
var salary :Int = 200{
    willSet(newValue){
        println("change the charge \(newValue)");
    }
    didSet(oldValue){
        if(salary >= (oldValue + 50)){
            println("amazing");
        }
    }
}
func showResult(){
    salary = 250;
}
showResult();
println(People.staticParam);
println(People.staticFunc());

//�±귽��
class Assistant{
    var interviewees:[Int:String] = [:];
    var name : String = "";
    //ʹ��subscript�ؼ���
    subscript (number : Int) -> String?{
        get{
            return interviewees[number];
        }
        set{
            interviewees[number] = newValue;
        }
    }
    subscript (number:Int , door : Int) ->String?{
        get{
            println("to the door of \(door)");
            return interviewees[number];
        }
    }
    //ǰ�����final���ɷ�ֹ����д
    class func staticMethods(){
        println("yes");
    }
}
var myAssistant = Assistant();
myAssistant.name = "assistant";
//ʹ�������±�ĸ�ʽֱ�ӽ��и�ֵ ������Ҫ�������飬�������ֵ�
myAssistant[2] = "name1";
myAssistant[32] = "name2";
//ͬ���ģ��±�Ҳ���Զ��ֵ 
//ע��ʹ��!�����
println(myAssistant[2]!);
println(myAssistant[32]!);
println(myAssistant[2,31]!);
//��ļ̳з�ʽ
class Assistant_Son:Assistant{
    override class func staticMethods(){
        println("override");
    }
}
Assistant_Son.staticMethods();
//�������ʵ��
class Buddna {
    var name : String;
    //������ͨ��ָ��������
    init(theFirstMethod name:String){
        println("first");
        self.name = name;
    }
    //��������������
    init(theSecondMethod name:String){
        println("second");
        self.name = name;
    }
    //���������� ���������������ķ���
    convenience init (){
        println("convenience");
        self.init(theSecondMethod:"theFirst");
    }
    //��ʧ�ܹ����������ڲ���������ʱ����null����
    init?(name : String){
        self.name = name;
        //����ʧ�ܱ��������
        if(name == "failed"){
            return nil;
        }
    }
    deinit{
        println("destroy");
    }
}
//���ù��췽����ͬʱ ���Ƕ������������˴��� ������һ��ǿ����
var buddna1:Buddna? = Buddna(theFirstMethod: "first");
var buddna2 = Buddna(theSecondMethod: "second");
//�ͷ���Դ ����destory����
//��1�п���ֱ�Ӹ�ֵΪnil ��Ϊ�ڶ����ʱ������ʹ���˿�ѡ����
buddna1 = nil;
//�������2һ�� ֻ����Buddna������װ��
buddna2 = Buddna(theFirstMethod: "123");
//ָ���������е���ʽ���ø��๹����
class base1 {
    var name1 : String;
    init(){
        self.name1 = "test";
        println("base init \(name1)" );
    }
}
class base2 : base1{
    var name2 : String;
    override init(){
        self.name2 = "base2";
        println("base2 name \(name2)");
        //��ʾ�ĵ���superinit֮��ʲſ���ʹ�����ֵ
        super.init();
        self.name1 = "name1";
    }
}
/*
output:
base2 name base2
base init test
*/
var testBase = base2();
//Ҫ��ס���ǣ���Swift�г���Class֮�⣬������ȫ����ֵ����
//ֵ�����и������������ʷ����������޸ĵ�ǰ��ʵ����������ͨ����ǰʵ���Ļ��������޸�����

struct WarCraft {
    var sence : String;
    var money : Int;
    mutating func jumpToSence(sence:String){
         //������ֱ������һ���µ�ʵ��
        self = WarCraft(sence: "new Sence", money: 123);
    }
    func toString(){
        println("sence " + self.sence);
        println("money  \(self.money)");
    }
}

func testMutiating(){
    var myWarCraft = WarCraft(sence: "sence1", money: 1100);
    myWarCraft.toString();
    //after
    myWarCraft.jumpToSence("die");
    myWarCraft.toString();
}
testMutiating();
//�ջ���ǿ���ã��������ڴ�й¶��Ԫ��
class Male{
    let name : String;
//   ʹ��ǿ����
//   var girl : Female?;
//   ʹ��������
//    weak var girl : Female?;
//    ʹ���������� ����������֮�� ��ʵ���Զ����� ����˵������1
//    ��girl���� boyҲѳ����
    unowned var girl : Female;
//  ������������ʱ����������������������ñ�����ֵ
//    init(name : String){
//        self.name = name;
//    }
    init(name : String , girl : Female){
        self.name = name;
        self.girl = girl;
    }
    deinit{
        println("die male");
    }
}

class Female {
    let name : String;
    weak var boy : Male?;
    init (name : String){
        self.name = name;
    }
    deinit{
        println("die fe");
    }
}
func deadLock(){
    //�������ڴ�й¶
    var woman : Female? = Female(name:"female");
    var man : Male? = Male(name: "male",girl:woman!);
    //������������Ҫʹ�ã�������ǿ�ƽ����ʹ�������ֵ
    //man!.girl =  woman;

    woman!.boy = man;
    println("deinit");
    //���������� girl����boyҲ�������
    //man = nil;
    woman = nil;
    println("finish");
}
deadLock();
