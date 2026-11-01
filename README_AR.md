# Chrono-Utils

[English](README.md) · [العربية](README_AR.md) · [فهرس الملفات](docs/INDEX_AR.md)

مكتبة تاريخ بلغة C++ وأمثلة طرفية لعمليات التواريخ.

## المحتوى

- [clData.h](clData.h)
- [DateNexu.cpp](DateNexu.cpp)
- [ShouliotionProfssoer.cpp](ShouliotionProfssoer.cpp)
- [RateMyProfessor.h](RateMyProfessor.h)

## الإعداد والاستخدام

يستدعي `DateNexu.cpp` الملف `clData.h` وهو مثال التاريخ الأساسي. ابنِه منفصلاً عن المثال الآخر:

```bat
cl /EHsc /std:c++17 DateNexu.cpp /Fe:chrono.exe
```

يستدعي `ShouliotionProfssoer.cpp` الملف `Data.h` غير الموجود في الشجرة المرفوعة؛ استعد الاعتماد أو صححه قبل بناء ذلك المثال.

يستخدم كود الطرفية أوامر Windows مثل `cls` أو `pause`، لذا Windows هو البيئة المقصودة. توضح الأوامر أدناه نقطة بناء المصدر، ولم تجر ترجمتها ضمن تحديث التوثيق.

[التوثيق السابق والتفاصيل الإضافية](README_DETAILS.md)

## الترخيص

لا يتضمن المستودع ملف ترخيص في الجذر حالياً. هذا التوثيق لا يضيف ترخيصاً جديداً.

## المساهمة والتنقل

[CONTRIBUTING.md](CONTRIBUTING.md) · [فهرس التوثيق](docs/INDEX_AR.md) · [فهرس المشاريع العامة](https://github.com/InfoSecNazir/InfoSecNazir/blob/main/PROJECTS_AR.md)

## نطاق التحقق

تمت مراجعة أسماء الملفات ومسارات التوثيق وملفات الحزم لتنظيم المستودع. لم يتم تشغيل التطبيق أو نشره ضمن هذا التحديث.
