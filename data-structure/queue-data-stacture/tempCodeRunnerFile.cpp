
    cout << "Front: " << ticket.front() << endl;
    cout << "Back: " << ticket.back() << endl;

    ticket.pop();
    cout << "After one pop:" << endl;
    ticket.print_queue();

    cout << "Queue size: " << ticket.size() << endl;
    cout << "Is queue empty? " << (ticket.empty() ? "Yes" : "No") << endl;