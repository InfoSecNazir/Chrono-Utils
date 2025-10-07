ChronoCore-CPP 🕰️
مكتبة C++ شاملة وقوية للتعامل المتقدم مع التاريخ والوقت

📖 حول المشروع (About The Project)
ChronoCore-CPP ليست مجرد مكتبة للتعامل مع التاريخ، بل هي تجسيد لفلسفة الهيمنة على المفاهيم الأساسية للبرمجة بلغة C++. وُلد هذا المشروع من رحم الشغف بالبرمجة الكائنية (OOP) والسعي لبناء أداة لا تتميز فقط بوظائفها الشاملة، بل أيضاً بكفاءتها وتصميمها النظيف.

المكتبة مصممة لتكون نواة (Core) لأي تطبيق يحتاج إلى عمليات دقيقة ومعقدة على الزمن (Chrono)، مقدمة واجهة برمجية (API) سهلة الاستخدام ومبنية بالكامل من الصفر.

✨ الميزات الرئيسية (Key Features)
بنية كائنية التوجه (OOP): تصميم متكامل يعتمد على الكائنات لتسهيل التعامل مع التواريخ.

عمليات حسابية متقدمة: دعم كامل لعمليات الجمع والطرح (أيام، أسابيع، أشهر، سنوات، عقود، وقرون).

تحميل زائد للمعاملات: استخدام بديهي لمعاملات المقارنة (<, >, ==) والزيادة والنقصان (++, --).

أدوات مساعدة قوية: مجموعة واسعة من الدوال المساعدة (static) للتحقق من السنة الكبيسة، عدد أيام الشهر، والمزيد.

طباعة التقويم: إمكانية طباعة تقويم كامل لشهر أو سنة محددة.

تحليل الفترات الزمنية: دوال للتحقق من تقاطع فترتين زمنيتين، وحساب طول فترة ما.

التعامل مع النصوص: تحويل التواريخ من وإلى نصوص (string) بسهولة، مع دعم تنسيقات مختلفة.

خصائص التاريخ: دوال لمعرفة خصائص أي تاريخ بسهولة (هل هو يوم عطلة؟ هل هو آخر يوم في الشهر؟).

🚀 البدء (Getting Started)
البدء في استخدام المكتبة بسيط جداً. كل ما تحتاجه هو تضمين ملف الترويسة clData.h (أو Date.h بعد إعادة التسمية) في مشروعك.

#include <iostream>
#include "clData.h" // <--- قم بتضمين المكتبة هنا

int main() {
    clData today(7, 10, 2025);
    std::cout << "Today is: " << today << std::endl;
    return 0;
}

💻 أمثلة الاستخدام (Usage Examples)
إليك لمحة سريعة عن قوة المكتبة:

1. إنشاء تاريخ وإجراء عمليات حسابية
#include "clData.h"

// ...

clData projectDeadline(15, 12, 2025);
cout << "Initial Deadline: " << projectDeadline << endl;

// Let's add 2 weeks to the deadline
projectDeadline.increses_one_Week_N(2);
cout << "Extended Deadline: " << projectDeadline << endl; // Output: 29/12/2025

// Go back 3 days
projectDeadline.Decreses_Day_N(3);
cout << "Final Deadline:   " << projectDeadline << endl; // Output: 26/12/2025

2. استخدام معاملات المقارنة والزيادة
clData date1(20, 10, 2025);
clData date2(25, 10, 2025);

if (date1 < date2) {
    cout << date1 << " comes before " << date2 << endl;
}

cout << "Counting days from date1 to date2:" << endl;
while (date1 <= date2) {
    cout << date1 << endl;
    date1++; // استخدام بديهي لمعامل الزيادة
}

3. استخدام الأدوات المساعدة (Static Utilities)
int year = 2024;
if (clData::Leap_Year(year)) {
    cout << year << " is a leap year." << endl;
}

int days = clData::Number_of_Day_Monthe(year, 2); // February 2024
cout << "Days in Feb 2024: " << days << endl; // Output: 29

4. طباعة تقويم شهر
// طباعة تقويم شهر أكتوبر 2025
clData calendar;
calendar.Print_Clenader_Monthe(10, 2025);

💡 فلسفة المشروع (Motivation)
"التكنولوجيا ليست مجرد أدوات نستخدمها، بل هي امتداد لإنسانيتنا." - راي كرزويل

هذا المشروع ليس مجرد تمرين برمجي، بل هو تطبيق عملي لهذه الفلسفة. بناء أداة دقيقة للتعامل مع الزمن - وهو المفهوم الأكثر تأثيراً في حياتنا - هو محاولة لتنظيم وفهم هذا الامتداد الإنساني من خلال منطق وهيكلية لغة C++.

🤝 المساهمة (Contributing)
المساهمات هي ما يجعل مجتمع المصادر المفتوحة مكاناً رائعاً للتعلم والإلهام والإبداع. أي مساهمات تقدمها هي موضع تقدير كبير.

قم بعمل Fork للمشروع.

أنشئ فرع الميزة الخاص بك (git checkout -b feature/AmazingFeature).

قم بعمل Commit لتغييراتك (git commit -m 'Add some AmazingFeature').

قم بالدفع إلى الفرع (git push origin feature/AmazingFeature).

افتح طلب سحب (Pull Request).

📜 الترخيص (License)
يتم توزيع المشروع بموجب ترخيص MIT. انظر LICENSE لمزيد من المعلومات.
