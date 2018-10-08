filename = 'avgOut.txt';

importData = csvread(filename);
rollingPulses = wkeep(importData(:,2),14300, 100);
timeInSeconds = round(importData(:,1));
timeInSeconds = wkeep(timeInSeconds, 14300, 100);
figure(1);
hold on
plot(timeInSeconds,rollingPulses);
title('Heart Rate During Sleep');
xlabel('Time (in hours)');
ylabel('BPM');
xticks((0:0.5:6)*3600);
xticklabels({'1:00', '1:30', '2:00', '2:30', '3:00', '3:30', '4:00', '4:30', '5:00', '5:30', '6:00', '6:30', '7:00'});