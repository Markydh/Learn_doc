/***
 * 工厂模式
 * 设计模式：创建型类模式
 */

public class factoryMode {
    public static void main(String[] args) {
        Factory factoryA = new SafeFactory();
        Product safe = factoryA.createProduct();
        safe.info();

        Factory factoryB = new HatFactory();
        Product hat = factoryB.createProduct();
        hat.info();
    }
}


interface  Factory{
    public Product createProduct();
}


class  SafeFactory implements Factory{
    @Override
    public  Product createProduct(){
        return new Safe();
    }
}

class HatFactory implements Factory{
    @Override
    public Product createProduct(){
        return new Hat();
    }
}


interface Product {
    public void info();
}


class Safe implements Product{
    @Override
    public void info(){
        System.out.println("生产一座沙发");
    }
}


class Hat implements Product{
    @Override
    public void info(){
        System.out.println("生产一顶帽子");
    }
}
