#include "managerwindow.h"

ManagerWindow::ManagerWindow()
{
    dateLabel = createLabel("Дата заполнения:");
    dateValueLabel = createLabel(createDate());
    fullNameLabel = createLabel("ФИО сотрудника:");
    fullNameLine = createEmptyLine(200);
    salaryLabel = createLabel("Оклад:");
    salaryLine = createEmptyLine(200);
    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine(200);
    calendarWorkingDaysLabel = createLabel("Рабочие дни:");
    calendarWorkingDaysLine = createEmptyLine(200);
    totalSalaryLabel = createLabel("Итоговая зп:");
    totalSalaryLine = createEmptyLine(200);
    calculateButton = createButton("Рассчитать");
    writeButton = createButton("Записать");
    backButton = createButton("Назад");
    sellProfitLabel = createLabel("Прибыль от продаж: ");
    sellProfitLine = createEmptyLine(200);
    managerProfitLabel = createLabel("Прибыль сотрудника:");
    managerProfitValueLabel = createEmptyLabel();
    payFundRadio = new QRadioButton("10% фонд отпускных");

    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    sellProfitLayout = createPackedHLayout(sellProfitLabel, sellProfitLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    payFundLayout = createPackedHLayout(payFundRadio);

    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryValueLabel);
    managerProfitLayout = createPackedHLayout(managerProfitLabel, managerProfitValueLabel);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = new QHBoxLayout;
    calculateLayout->addWidget(calculateButton);
    calculateLayout->addWidget(writeButton);
    backLayout = createPackedHLayout(backButton);

    //managerLayouts = {dateLayout, fullNameLayout, sellProfitLayout, workingDaysLayout, calendarWorkingDaysLayout,
    //                 payFundLayout, minSalaryLayout,   managerProfitLayout, totalSalaryLayout, calculateLayout, backLayout};
    //managerMainLayout = createMainLayout(managerLayouts);
    managerMainLayout = new QGridLayout;
    managerMainLayout->addLayout(dateLayout, 0, 0);
    managerMainLayout->addLayout(fullNameLayout, 1, 0);
    managerMainLayout->addLayout(sellProfitLayout, 2, 0);
    managerMainLayout->addLayout(workingDaysLayout, 3, 0);
    managerMainLayout->addLayout(calendarWorkingDaysLayout, 4, 0 );
    managerMainLayout->addLayout(payFundLayout, 5, 0, Qt::AlignRight);
    managerMainLayout->addLayout(minSalaryLayout, 6, 0 );
    managerMainLayout->addLayout(managerProfitLayout, 7, 0 );
    managerMainLayout->addLayout(totalSalaryLayout, 8, 0 );
    managerMainLayout->addLayout(calculateLayout, 9, 0 );
    managerMainLayout->addLayout(backLayout, 10, 0);


    managerWidget = createWidget(managerMainLayout);
    setCentralWidget(managerWidget);
    setWindowTitle("Расчет зарплаты менеджера");
}

ManagerWindow::~ManagerWindow()
{

}
