import java.util.*;

/**
 * 摩尔投票算法又称为多数投票算法
 *
 * <p>最基本的摩尔投票问题，找出一组数字序列中出现次数大于总数1/2的数字（并且假设这个数字一定存在）。显然这个数字只可能有一个。摩尔投票算法是基于这个事实：每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个。</p>
 *
 *
 * 实现的算法从第一个数开始扫描整个数组，有两个变量(参考第一答题者的变量名)major和count。其实这两个变量想表达的是一个“隐形的数组”array，array存储的是“当前暂时无法删除的数字”，我们先不要管major和count，只考虑这个array，同时再维护一个结果数组result，result里面存储的是每次删除一对元素之后的当前结果。为了方便理解举一个示例输入：{1,2,1,3,1,1,2,1,5}从第一个数字1开始，我们想要把它和一个不是1的数字一起从数组里抵消掉，但是目前我们只扫描了一个1，所以暂时无法抵消它，把它加入到array，array变成了{1}，result由于没有抵消任何元素所以还是原数组{1,2,1,3,1,1,2,1,5}。然后继续扫描第二个数，是2，我们可以把它和一个不是2的数字抵消掉了，因为我们之前扫描到一个1，所以array变成了{},result变成了{1,3,1,1,2,1,5}继续扫描第三个数1，无法抵消，于是array变成了{1},result还是{1,3,1,1,2,1,5};接下来扫描到3,可以将3和array数组里面的1抵消,于是array变成了{},result变成了{1,1,2,1,5}接下来扫描到1，此时array为空，所以无法抵消这个1，array变成了{1},result还是{1,1,2,1,5}接下来扫描到1，此时虽然array不为空，但是array里也是1，所以还是无法抵消，把它也加入这个array,于是array变成了{1,1}（其实到这我们可以发现，array里面只可能同时存在一种数，因为只有array为空或当前扫描到的数和array里的数字相同时才把这个数字放入array）,result还是{1,1,2,1,5}接下来扫描到2，把它和一个1抵消掉，至于抵消哪一个1，无所谓，array变成了{1},result是{1,1,5}接下来扫描到1，不能抵消，array变成了{1,1}，result{1,1,5}接下来扫描到5，可以将5和一个1抵消，array变成了{1},result变成了{1}至此扫描完成了数组里的所有数，result里剩了1，所以1就是大于一半的数组。再回顾一下这个过程，其实就是删除（抵消）了（1，2），（1，3），（1，5）剩下了一个1。除去冗余关系：实际代码中没有array，也没有result，因为我们不需要。由于前面提到array里只可能同时存储一种数字，所以我们用major来表示当前array里存储的数，count表示array的长度,即目前暂时无法删除的元素个数，最后扫描完所有的数字，array和result变成一样了，都表示“最后还是无法删除的数字”。
 */
class Scratch {
    public static void main(String[] args) {
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            int major = random.nextInt(10000);
            int[] testSet = genData(random.nextInt(1000) + 1, major);
            int r = moore(testSet);
            if (r != major) {
                System.out.println("数组：" + Arrays.toString(testSet) + " major:" + major + " r:" + r);
                System.out.println("---------------------------");
            }
        }
    }

    public static int moore(int[] array) {
        if (array == null || array.length == 0) {
            throw new RuntimeException("不合法的参数");
        }
        int major = array[0];
        int len = 1;
        for (int i = 1; i < array.length; i++) {
            if (len == 0) {
                major = array[i];
                len++;
            } else {
                if (major == array[i]) {
                    len++;
                } else {
                    len--;
                }
            }
        }
        return major;
    }

    /**
     * 摩尔投票算法
     */
    public static int[] genData(int len, int major) {
        Random random = new Random();
        int majorCnt = random.nextInt(len / 2) + 1 + (len / 2);
        List<Integer> l = new ArrayList<>(len);
        for (int i = 0; i < majorCnt; i++) {
            l.add(major);
        }
        for (int i = 0; i < len - majorCnt; i++) {
            l.add(random.nextInt(50));
        }
        Collections.shuffle(l);

        int[] r = new int[len];
        for (int i = 0; i < l.size(); i++) {
            r[i] = l.get(i);
        }
        return r;
    }
}
