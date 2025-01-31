public class LC2125 {
    public int numberOfBeams(String[] bank) {
        int answer = 0, preLaserCount = 0;
        for (String s : bank) {
            int laserCount = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '1') laserCount++;
            }
            answer += preLaserCount * laserCount;
            if (laserCount > 0) preLaserCount = laserCount;
        }

        return answer;
    }
}