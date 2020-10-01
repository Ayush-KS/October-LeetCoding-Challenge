// Number of Recent Calls

class RecentCounter {
    Deque<Integer> dq;
    
    public RecentCounter() {
        dq = new LinkedList<Integer>();
    }
    
    public int ping(int t) {
        dq.addLast(t);
        while(dq.getFirst() < (dq.getLast() - 3000)) {
            dq.pollFirst();
        }
        return dq.size();
    }
}