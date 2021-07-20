#include "managerwindow.h"

ManagerWindow::ManagerWindow()
{
    dateLabel = createLabel("Дата заполнения:");
    dateValueLabel = createLabel(createDate());
    fullNameLabel = createLabel("ФИО сотрудника:");
    fullNameLine = createEmptyLine();
    salaryLabel = createLabel("Оклад:");
    salaryLine = createEmptyLine();
    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine();
    calendarWorkingDaysLabel = createLabel("Рабочие дни:");
    calendarWorkingDaysLine = createEmptyLine();
    totalSalaryLabel = createLabel("Итоговая зп:");
    totalSalaryLine = createEmptyLine();
    calculateButton = createButton("Рассчитать");
    writeButton = createButton("Записать");
    backButton = createButton("Назад");
    sellProfitLabel = createLabel("Прибыль от продаж: ");
    sellProfitLine = createEmptyLine();
    managerProfitLabel = createLabel("Прибыль сотрудника:");
    managerProfitValueLabel = createEmptyLabel();
    payFundRadio = new QRadioButton("10% фонд отпускных");
    sellPercentLabel = new QLabel("Процент менеджера:");
    sellPercentLabel->setAlignment(Qt::AlignCenter);
    fourPercent = new QRadioButton("4%");
    sevenPercent = new QRadioButton("7%");
    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    sellProfitLayout = createPackedHLayout(sellProfitLabel, sellProfitLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    payFundLayout = createPackedHLayout(payFundRadio);
    sellPercentLayout = createPackedHLayout(sellPercentLabel);
    percentButtonsLayout = createPackedHLayout(fourPercent, sevenPercent);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryValueLabel);
    managerProfitLayout = createPackedHLayout(managerProfitLabel, managerProfitValueLabel);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createPackedHLayout(calculateButton, writeButton);
    backLayout = createPackedHLayout(backButton);

    managerLayouts = {dateLayout, fullNameLayout, sellProfitLayout, workingDaysLayout, calendarWorkingDaysLayout,
                     payFundLayout, sellPercentLayout, percentButtonsLayout, intermediateSalaryLayout, penaltyLayout,
                     premiumLayout, adjustmentLayout, minSalaryLayout, managerProfitLayout, totalSalaryLayout, calculateLayout, backLayout};
    managerMainLayout = createMainLayout(managerLayouts);
    managerWidget = createWidget(managerMainLayout);
    setCentralWidget(managerWidget);
    setWindowTitle("Расчет зарплаты менеджера");
}

ManagerWindow::~ManagerWindow()
{

}
