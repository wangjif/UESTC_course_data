
close all
%���������������
t = 0:pi/3:2*pi;
r = 5;
x = r*cos(t);
y = r*sin(t); %�������������6���ڵ�����(������7����������㣬�ص��غϣ�

x = x + 6; % ƽ��һ�µõ���ʼ�������ζ�������
y = y + 6;
tt = 2*pi/200;
P = [x
     y];
M = rotM(tt); %ÿ�ζ�����ת�Ƕȶ�Ϊtt
for i=1:200    
    PNew = M*P;
    P = PNew;
    
    plot(P(1,:),P(2,:),'r-')
    axis([-30 30 -30 30])
    axis equal
    pause(0.02)
end

function M= rotM(t)
%�������tΪ��ת�Ƕ�
M = [cos(t),-sin(t)
     sin(t),cos(t)];
end