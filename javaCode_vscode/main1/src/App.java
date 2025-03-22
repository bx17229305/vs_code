import java.lang.annotation.Annotation;
import java.lang.reflect.AnnotatedType;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class App
{

    static void f(int... nums)
    {
        Class<?> clz = nums.getClass();
        System.out.println(clz);
    }

    public static void main(String[] args) throws Exception
    {
        Class clz = Dog.class;
        Annotation[] annotations = clz.getAnnotations();
        for (Annotation annotation : annotations)
        {
            Class class1 = annotation.getClass();
            Method[] methods = class1.getMethods();
            for (Method methods2 : methods) {
                \
            }
        }

    }
}
