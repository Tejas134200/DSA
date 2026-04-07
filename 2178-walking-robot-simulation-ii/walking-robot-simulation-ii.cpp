class Robot {
public:
    int w , h;
    int x,y,dir;
    vector<string> d;

    Robot(int width, int height) {
        x=0;
        y=0;
        w=width;
        h=height;
        d = {"North","East","South","West"};
        dir =1;
    }
    
    void step(int num) {
        int cycle = 2 * (w + h - 2);
        num %= cycle;

        if(num == 0){
            if(x == 0 && y == 0) dir = 2;
            return;
        }

        while(num > 0){

            if(dir == 1){
                int mini = min(w - x - 1, num);
                if(mini == 0){ dir = 0; continue; }
                num -= mini;
                x += mini;
                if(num > 0) dir = 0;
            }
            else if(dir == 0){
                int mini = min(h - y - 1, num);
                if(mini == 0){ dir = 3; continue; }
                num -= mini;
                y += mini;
                if(num > 0) dir = 3;
            }
            else if(dir == 2){
                int mini = min(y, num);
                if(mini == 0){ dir = 1; continue; }
                num -= mini;
                y -= mini;
                if(num > 0) dir = 1;
            }
            else if(dir == 3){
                int mini = min(x, num);
                if(mini == 0){ dir = 2; continue; }
                num -= mini;
                x -= mini;
                if(num > 0) dir = 2;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return d[dir];
    }
};