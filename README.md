物件導向期末專題
我們可以把「劍士」物件的成員變數atk（攻擊力）宣告為private，再宣告一個public方法來執行攻擊，例如叫它attack（）方法。attack（）方法的定義會使用到atk這個private變數來做計算，例如：傷害值 = atk數值 * 裝備加成 * 命中率。
這樣我們就達到目的：即我們既可以防止使用者隨意亂改劍士的atk數值，也可以透過attack（）這個public方法來存取atk這個private變數，和其他物件做互動，例如造成了「暗黑龍」這個物件350點的傷害。
