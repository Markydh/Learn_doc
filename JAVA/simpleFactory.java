/**
 * 设计模式
 * 简单工厂模式
 * 设计模式类型：创建型设计模式
 * */

 import java.util.Scanner;

 public class simpleFactory {
     public static void main(String[] args) {
         Scanner  scanner = new Scanner(System.in);
         String type;
         System.out.println("想要生产的产品是:");
         type = scanner.next();
         Product product = Factory.createProduct(type);
         product.info();
     }
 }
 
 
 
 class Factory{
     public static Product createProduct(String type){
         Product product = null;
         switch (type){
             case "safe" :{
                 product = new Safe();
                 break;
             }
             case "shoe":{
                 product = new Shoe();
                 break;
             }
             default:{
                 System.out.println("没有合适的产品");
             }
         }
         return product;
     }
 }
 
 //创建一个抽象类
 abstract class Product{
     public abstract void info();
 }
 
 
 //继承抽象类，重写父类的方法
 class Safe extends Product{
     @Override
     public void info(){
         System.out.println("生成沙发");
     }
 }
 
 class Shoe extends Product{
     @Override
     public void info(){
         System.out.println("你购买了鞋子");
     }
 }
 