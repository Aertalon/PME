#include <thread>

class Timer {
    bool active_ = true;

public:
    /// Sets the timeout
    /// @param function The functor that must be executed after delay ms
    /// @param delay The timeout [ms]
    /// @tparam F The functor class
    template<class F>
    void setTimeout(F function, int delay)
    {
        active_ = true;
        std::thread t([=]() {
            if(!active_) return;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            if(!active_) return;
            function();
        });
        t.detach();
    }

    /// Sets the time interval
    /// @param function The functor that must be executed every interval ms
    /// @param interval The time step of the timer [ms]
    /// @tparam F The functor class
    template<class F>
    void setInterval(F function, int interval)
    {
        active_ = true;
        std::thread t([=]() {
            while(true)
            {
                if(!active_) return;
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                if(!active_) return;
                function();
            }
        });
        t.detach();
    }

    /// Stops the timer
    void stop()
    {
        active_ = false;
    }

    /// Whether the timer is active
    bool is_active()
    {
        return active_;
    }
};