for x=0:14
    for y=0:18
        left=1200-x*85-y*64;
        if(left>=0 & left<64)
            fprintf("85����%d����64����%d��������%d����\n",x,y,left);
        end
    end
end

     