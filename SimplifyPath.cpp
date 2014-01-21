class Solution {
public:
    string simplifyPath(string path) {
        //the length of path in test case may bigger than 260
    	char cpath[1500];
    	strncpy(cpath, path.c_str(), sizeof(cpath));
    	cpath[sizeof(cpath) - 1] = '\0';

    	removeSplash(cpath, strlen(cpath));
    	removeOneDot(cpath, strlen(cpath));
    	removeTwoDot(cpath, strlen(cpath));

    	if (strlen(cpath) > 1 && cpath[strlen(cpath) - 1] == '/') {
    		cpath[strlen(cpath) - 1] = '\0';
    	}

    	return string(cpath);
    }

    //remove redundant splashs
    void removeSplash(char* path, int len) {
    	char* target = strstr(path, "//");

    	if (target) {
    		//will move '\0'
    		memmove(target, target + 1, (len - (target - path + 1) + 1) * sizeof(char));
    		return removeSplash(path, len - 1);
    	}

    	return;
    }

    //remove Two Dot
    void removeTwoDot(char* path, int len) {

    	//head ../
    	if (len >= 3 && strncmp(path, "../", 3) == 0) {
    		memmove(path, path + 2, len - 2 + 1);
    		len = len - 2;
    	}

    	if (len >= 3 && strncmp(path + len - 3, "/..", 3) == 0) {
            path[len] = '/';
            path[len + 1] = '\0';
            len = len + 1;
    	}

    	char* target = strstr(path, "/../");
    	if (target) {
    		char* after = target + 3;
    		while (target > path) {
    			if (*(--target) == '/') {
    				break;
    			}
    		}
    		//will move '\0'
    		memmove(target, after, (len - (after - path)  + 1) * sizeof(char));
    		return removeTwoDot(path, len - (after - target));
    	}

    	return;
    }

    //remove one Dot
    void removeOneDot(char* path, int len) {

    	//head ./
    	if (*(path) == '.' && *(path + 1) == '/') {
    		//will move '\0'
    		memmove(path, path + 1, len - 1 + 1);
    	}

    	//tail /.
    	if (len >= 2 && path[len - 1] == '.' && path[len - 2] == '/') {
    		path[len - 1] = '\0';
    		len = len - 1;
    	}

    	char* target = strstr(path, "/./");
    	if (target) {
    		memmove(target, target + 2, len - (target + 2 - path) + 1);
    		return removeOneDot(path, len - 2);
    	}

    	return;
    }
};